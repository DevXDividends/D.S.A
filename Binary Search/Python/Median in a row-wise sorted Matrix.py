# ------------------------------------------------------------
# 🧠 Brute Force Approach
# TC: O(n × m × log(n × m))
# SC: O(n × m)
# ------------------------------------------------------------
class BruteForceSolution:
    def median(self, mat):
        rows = len(mat)
        cols = len(mat[0])

        # Flatten the matrix into a single list
        arr = [mat[i][j] for i in range(rows) for j in range(cols)]

        # Sort the entire list
        arr.sort()

        # Return the middle element (median)
        return arr[len(arr) // 2]


# ------------------------------------------------------------
# ⚡ Optimal Approach (Binary Search on Value Range)
# TC: O(rows × log(maxVal - minVal) × log(cols))
# SC: O(1)
# ------------------------------------------------------------
import bisect

class OptimalSolution:
    def count_smaller_equal(self, mat, x):
        """
        Count how many elements in the matrix are <= x
        Using upper_bound (bisect_right) for each sorted row
        """
        cnt = 0
        for row in mat:
            cnt += bisect.bisect_right(row, x)
        return cnt

    def median(self, mat):
        rows = len(mat)
        cols = len(mat[0])

        # Step 1: Find the minimum and maximum elements in matrix
        low = min(row[0] for row in mat)
        high = max(row[-1] for row in mat)

        required = (rows * cols) // 2

        # Step 2: Binary search on the value range
        while low <= high:
            mid = low + (high - low) // 2
            count = self.count_smaller_equal(mat, mid)

            if count <= required:
                low = mid + 1
            else:
                high = mid - 1

        # Step 3: 'low' will be the median
        return low


# ------------------------------------------------------------
# 🧪 Example Usage (Optional for GitHub README)
# ------------------------------------------------------------
if __name__ == "__main__":
    matrix = [
        [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]
    ]

    brute = BruteForceSolution()
    optimal = OptimalSolution()

    print("Brute Force Median:", brute.median(matrix))
    print("Optimal Median:", optimal.median(matrix))

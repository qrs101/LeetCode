package main

func spiralOrder(matrix [][]int) []int {
	res := make([]int, 0)
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return res
	}
	row, col := len(matrix), len(matrix[0])
	seen := make([][]bool, row)
	for i := range seen {
		seen[i] = make([]bool, col)
	}
	addRow, addCol := []int{0, 1, 0, -1}, []int{1, 0, -1, 0}
	i, j, add := 0, 0, 0
	for k := 0; k < row * col; k++ {
		res = append(res, matrix[i][j])
		seen[i][j] = true
		nextI, nextJ := i + addRow[add], j + addCol[add]
		condition1 := 0 <= nextI && nextI < row
		condition2 := 0 <= nextJ && nextJ < col
		if condition1 && condition2 && !seen[nextI][nextJ]{
			i, j = nextI, nextJ
		} else {
			add = (add + 1) % 4
			i, j = i + addRow[add], j + addCol[add]
		}
	}
	return res
}
package main

func generateMatrix(n int) [][]int {
	res := make([][]int, n, n)
	for k := 0; k < n; k++ {
		res[k] = make([]int, n, n)
	}
	row, col := []int{0, 1, 0, -1}, []int{1, 0, -1, 0}
	i, j, index := 0, 0, 0
	for k := 1; k <= n * n; k++ {
		res[i][j] = k
		nextI, nextJ := i + row[index], j + col[index]
		if 0 <= nextI && nextI < n && 0 <= nextJ && nextJ < n && res[nextI][nextJ] == 0 {
			i, j = nextI, nextJ
		} else {
			index = (index + 1) % 4
			i, j = i + row[index], j + col[index]
		}
	}
	return res
}
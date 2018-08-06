package main

func rotate(matrix [][]int) {
	n := len(matrix) - 1
	for i, j := 0, n; i < j; i, j = i + 1, j - 1 {
		matrix[i], matrix[j] = matrix[j], matrix[i]
	}
	for i := 0; i <= n; i++ {
		for j := 0; j < i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}
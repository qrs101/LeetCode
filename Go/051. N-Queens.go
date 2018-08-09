package main

import "strings"

func check(board [][]string, i, j int) bool {
	n := len(board)
	for k := 0; k < n; k++ {
		if k != j && board[i][j] == "Q" {
			return false
		}
	}

	for k := 0; k < n; k++ {
		if k != i && board[k][j] == "Q" {
			return false
		}
	}

	for k1, k2 := i - 1, j - 1; k1 >= 0 && k2 >= 0; k1, k2 = k1 - 1, k2 - 1 {
		if board[k1][k2] == "Q" {
			return false
		}
	}

	for k1, k2 := i + 1, j + 1; k1 < n && k2 < n; k1, k2 = k1 + 1, k2 + 1 {
		if board[k1][k2] == "Q" {
			return false
		}
	}

	for k1, k2 := i + 1, j - 1; k1 < n && k2 >= 0; k1, k2 = k1 + 1, k2 - 1 {
		if board[k1][k2] == "Q" {
			return false
		}
	}

	for k1 ,k2 := i - 1, j + 1; k1 >= 0 && k2 < n; k1, k2 = k1 - 1, k2 + 1 {
		if board[k1][k2] == "Q" {
			return false
		}
	}

	return true
}

func board2res(board [][]string) []string {
	res := make([]string, len(board), len(board))
	for i := 0; i < len(board); i++ {
		res[i] = strings.Join(board[i], "")
	}
	return res
}

func solveNQueens(n int) [][]string {
	res := make([][]string, 0)
	board := make([][]string, n, n)
	for i := 0; i < n; i++ {
		board[i] = make([]string, n, n)
		for j := 0; j < n; j++ {
			board[i][j] = "."
		}
	}
	row, col, top := make([]int, n, n), make([]int, n, n), -1
	for i, j := 0, 0; i < n; i++ {
		for ; j < n; j++ {
			if check(board, i, j) {
				board[i][j] = "Q"
				top++
				row[top], col[top] = i, j
				j = 0
				break
			}
		}
		if top < 0 {
			break
		}
		if j == n {
			i, j = row[top], col[top]
			top--
			board[i][j] = "."
			i, j = i - 1, j + 1
		}
		if i == n - 1 && j != n {
			res = append(res, board2res(board))
			i, j = row[top], col[top]
			top--
			board[i][j] = "."
			i, j = i - 1, j + 1
		}
	}
	return res
}
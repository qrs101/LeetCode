package main

func isValidSudoku(board [][]byte, i int, j int, filling byte) bool {
	for k := 0; k < 9; k++ {
		if k != j && board[i][k] == filling {
			return false
		}
	}

	for k := 0; k < 9; k++ {
		if k != i && board[k][j] == filling {
			return false
		}
	}

	for I := i / 3 * 3; I < i / 3 * 3 + 3; I++ {
		for J := j / 3 * 3; J < j / 3 * 3 + 3; J++ {
			if (I != i || J != j) && board[I][J] == filling {
				return false
			}
		}
	}
	return true
}

func solveSudoku(board [][]byte) {
	row, col := make([]int, 100, 100), make([]int, 100, 100)
	top := -1
	var filling byte = '1'
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				continue
			}
			for ; filling <= '9'; filling++ {
				board[i][j] = filling
				if isValidSudoku(board, i, j, filling) {
					break
				}
			}
			if filling > '9' {
				board[i][j] = '.'
				if top >= 0 {
					i, j = row[top], col[top]
					filling = board[i][j] + 1
					board[i][j] = '.'
					j--
					top--
				} else {
					return
				}
			} else {
				top++
				row[top], col[top] = i, j
				filling = '1'
			}
		}
	}
	return
}

/*
func main() {
	board := [][]byte {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}
	solveSudoku(board)
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Print(board[i][j] - '0', " ")
		}
		fmt.Println()
	}
}
*/
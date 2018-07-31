package main

func isValidSudoku(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		haveNum := map[byte]bool {
			'1':false, '2':false, '3':false, '4':false, '5':false,
			'6':false, '7':false, '8':false, '9':false,
		}
		for j := 0; j < 9; j++ {
			if board[i][j] == '.' {
				continue
			}
			if haveNum[board[i][j]] == false {
				haveNum[board[i][j]] = true
			} else {
				return false
			}
		}
	}

	for j := 0; j < 9; j++ {
		haveNum := map[byte]bool {
			'1':false, '2':false, '3':false, '4':false, '5':false, 
			'6':false, '7':false, '8':false, '9':false,
		}
		for i := 0; i < 9; i++ {
			if board[i][j] == '.' {
				continue
			}
			if haveNum[board[i][j]] == false {
				haveNum[board[i][j]] = true
			} else {
				return false
			}
		}
	}

	for I := 0; I < 3; I++ {
		for J := 0; J < 3; J++ {
			haveNum := map[byte]bool {
				'1':false, '2':false, '3':false, '4':false, '5':false, 
				'6':false, '7':false, '8':false, '9':false,
			}
			for i := 0; i < 3; i++ {
				for j := 0; j < 3; j++ {
					if board[I * 3 + i][J * 3 + j] == '.' {
						continue
					}
					if haveNum[board[I * 3 + i][J * 3 + j]] == false {
						haveNum[board[I * 3 + i][J * 3 + j]] = true
					} else {
						return false
					}
				}
			}
		}
	}

	return true
}
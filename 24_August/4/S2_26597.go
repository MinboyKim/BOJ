package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var checkFlag int = 0

var checkLoc int

func Para(a int) {
	fmt.Println("Paradox!")
	fmt.Println(a)
	os.Exit(0)
}

func check(minA int64, maxA int64, i int) {
	if minA == maxA && checkFlag == 0 {
		checkFlag = 1
		checkLoc = i
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	tStr, _ := reader.ReadString('\n')
	t, _ := strconv.Atoi(strings.TrimSpace(tStr))

	minFlag := 0
	maxFlag := 0
	var minA int64 = 0
	var maxA int64 = 0
	for i := 0; i < t; i++ {
		line, _ := reader.ReadString('\n')
		parts := strings.Fields(line)
		a, _ := strconv.ParseInt(parts[0], 10, 64)
		b := parts[1]

		if b == "^" {
			if minFlag == 0 {
				minA = a + 1
			} else {
				minA = max(minA, a+1)
			}
			minFlag = 1

			if a == 999999999999999999 && checkFlag == 0 {
				checkFlag = 1
				checkLoc = i + 1
			}

			if a == 1000000000000000000 {
				Para(i + 1)
			}

			if maxFlag != 0 {
				if maxA < minA {
					Para(i + 1)
				}
				if minA == maxA && checkFlag == 0 {
					checkFlag = 1
					checkLoc = i + 1
				}
			}
		}
		if b == "v" {
			if maxFlag == 0 {
				maxA = a - 1
			} else {
				maxA = min(maxA, a-1)
			}

			maxFlag = 1

			if a == -999999999999999999 && checkFlag == 0 {
				checkFlag = 1
				checkLoc = i + 1
			}

			if a == -1000000000000000000 {
				Para(i + 1)
			}

			if minFlag != 0 {
				if maxA < minA {
					Para(i + 1)
				}
				if minA == maxA && checkFlag == 0 {
					checkFlag = 1
					checkLoc = i + 1
				}
			}

		}

	}
	if checkFlag == 1 {
		fmt.Println("I got it!")
		fmt.Println(checkLoc)
	} else {
		fmt.Println("Hmm...")
	}
}

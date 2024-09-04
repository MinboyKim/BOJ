package main

import (
	"fmt"
)

func main() {
	var a, b, c float32
	_, err := fmt.Scan(&a, &b, &c)

	if err != nil {
		return
	}


	var k = a / b * c

	fmt.Printf("%.6f", k)
}

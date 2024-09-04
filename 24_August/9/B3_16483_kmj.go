package main

import (
	"fmt"
	"math"
)

func main() {
	var a float64

	fmt.Scan(&a)

	fmt.Printf("%.0f", math.Round((a/2)*(a/2)))
}

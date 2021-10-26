package utils

import (
	"fmt"
	"testing"
)

func TestFindMinMax(t *testing.T) {
	min, max := FindMinMax([]float64{-1, -2, 100, -10, 30})
	fmt.Println(min, max)
}

func TestDistribute(t *testing.T) {
	fmt.Print(Distribute([]float64{-1, -2, 100, -10, 30}, 110))
}

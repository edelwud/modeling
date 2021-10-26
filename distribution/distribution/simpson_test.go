package distribution

import (
	"fmt"
	"testing"
)

func TestSimpson_Generate(t *testing.T) {
	simpsonGen := CreateSimpsonDistribution(10, 20, 10)
	simpsonDist := simpsonGen.Generate()
	fmt.Println(simpsonDist)
}

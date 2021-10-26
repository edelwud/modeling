package distribution

import (
	"fmt"
	"testing"
)

func TestRandom_Generate(t *testing.T) {
	randGen := CreateRandomDistribution(10)
	randDist := randGen.Generate()
	fmt.Println(randDist)
}

package distribution

import (
	"fmt"
	"testing"
)

func TestExponential_Generate(t *testing.T) {
	expGen := CreateExponentialDistribution(10, 10)
	expDist := expGen.Generate()
	fmt.Println(expDist)
}

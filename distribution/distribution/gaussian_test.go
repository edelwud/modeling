package distribution

import (
	"fmt"
	"testing"
)

func TestGaussian_Generate(t *testing.T) {
	gaussianGen := CreateGaussianDistribution(12, 32, 6, 10)
	gaussianDist := gaussianGen.Generate()
	fmt.Println(gaussianDist)
}

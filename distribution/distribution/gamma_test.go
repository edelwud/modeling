package distribution

import (
	"fmt"
	"testing"
)

func TestGamma_Generate(t *testing.T) {
	gammaGen := CreateGammaDistribution(10, 12, 10)
	gammaDist := gammaGen.Generate()
	fmt.Println(gammaDist)
}

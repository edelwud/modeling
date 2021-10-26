package distribution

import (
	"fmt"
	"testing"
)

func TestUniform_Generate(t *testing.T) {
	uniGen := CreateUniformDistribution(10, 20, 10)
	uniDist := uniGen.Generate()
	fmt.Println(uniDist)
}

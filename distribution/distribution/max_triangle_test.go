package distribution

import (
	"fmt"
	"testing"
)

func TestMaxTriangle_Generate(t *testing.T) {
	maxTriangleGen := CreateMaxTriangleDistribution(10, 20, 10)
	maxTriangleDist := maxTriangleGen.Generate()
	fmt.Println(maxTriangleDist)
}

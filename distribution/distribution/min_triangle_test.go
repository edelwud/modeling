package distribution

import (
	"fmt"
	"testing"
)

func TestMinTriangle_Generate(t *testing.T) {
	minTriangleGen := CreateMinTriangleDistribution(10, 20, 10)
	minTriangleDist := minTriangleGen.Generate()
	fmt.Println(minTriangleDist)
}

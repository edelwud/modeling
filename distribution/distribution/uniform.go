package distribution

type Uniform struct {
	a      float64
	b      float64
	length int
}

func (u Uniform) Generate() []float64 {
	randGen := CreateRandomDistribution(u.length)
	randDist := randGen.Generate()

	uniform := make([]float64, u.length)
	for i := range uniform {
		uniform[i] = u.a + (u.b-u.a)*randDist[i]
	}

	return uniform
}

func CreateUniformDistribution(a float64, b float64, length int) Distribution {
	return &Uniform{
		a:      a,
		b:      b,
		length: length,
	}
}

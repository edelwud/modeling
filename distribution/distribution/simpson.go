package distribution

type Simpson struct {
	a      float64
	b      float64
	length int
}

func (s Simpson) Generate() []float64 {
	randGenY := CreateRandomDistribution(s.length)
	randDistY := randGenY.Generate()

	randGenZ := CreateRandomDistribution(s.length)
	randDistZ := randGenZ.Generate()

	simpson := make([]float64, s.length)

	for i := 0; i < s.length; i++ {
		y := s.a/2 + (s.b/2-s.a/2)*randDistY[i]
		z := s.a/2 + (s.b/2-s.a/2)*randDistZ[i]
		simpson[i] = y + z
	}

	return simpson
}

func CreateSimpsonDistribution(a float64, b float64, length int) Distribution {
	return &Simpson{
		a:      a,
		b:      b,
		length: length,
	}
}

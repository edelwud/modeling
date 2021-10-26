package distribution

type Distribution interface {
	Generate() []float64
}

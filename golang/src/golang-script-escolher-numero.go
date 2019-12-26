package main

import (
	"bufio"
	"fmt"
	"os"
)

var e bool = false

func start() {
	fmt.Println(`

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================`)

	if e == true {
		fmt.Println("\n\nINSIRA APENAS '1' OU '2'")
	}

	reader := bufio.NewReader(os.Stdin)
	acaoInicial, _, err := reader.ReadRune()

	if err != nil {
		fmt.Println(err)
	}

	switch acaoInicial {
	case '1':
		num()
		break
	case '2':
		coin()
		break
	}

	if acaoInicial != '1' && acaoInicial != '2' {
		if acaoInicial == 'q' {
		} else {
			e = true
			start()
		}
	}
}

func num() {
	fmt.Println("11111111111111")
}

func coin() {
	fmt.Println("22222222222222")
}

func main() {

	start()
}

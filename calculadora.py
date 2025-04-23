def somar(x, y):
    return x + y

def subtrair(x, y):
    return x - y

def multiplicar(x, y):
    return x * y

def dividir(x, y):
    if y == 0:
        return "Erro: divisão por zero!"
    return x / y

def calculadora():
    print("Selecione a operação:")
    print("1 - Soma")
    print("2 - Subtração")
    print("3 - Multiplicação")
    print("4 - Divisão")

    escolha = input("Digite sua escolha (1/2/3/4): ")

    if escolha in ['1', '2', '3', '4']:
        try:
            num1 = float(input("Digite o primeiro número: "))
            num2 = float(input("Digite o segundo número: "))

            if escolha == '1':
                print("Resultado:", somar(num1, num2))
            elif escolha == '2':
                print("Resultado:", subtrair(num1, num2))
            elif escolha == '3':
                print("Resultado:", multiplicar(num1, num2))
            elif escolha == '4':
                print("Resultado:", dividir(num1, num2))
        except ValueError:
            print("Erro: insira apenas números válidos.")
    else:
        print("Opção inválida.")

calculadora()

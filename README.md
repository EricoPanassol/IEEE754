# IEEE754

## Disciplina: Métodos Numéricos
Estudo e construção de modelos matemáticos na solução de problemas computacionais. Utilização adequada da aritmética de ponto flutuante. Análise dos fundamentos matemáticos de algoritmos numéricos. Identificação dos problemas de implementações em ponto flutuante. Apresentação dos conceitos que sustentam algoritmos numéricos e aplicação desses conceitos para a computação numérica eficiente. Realização de computação científica através da programação de algoritmos numéricos.


### Trabalho 1

Seu primeiro trabalho nesta disiplina onsiste em explorar o padrão IEEE-754. Voê deve
implementar um programa que cumpra as seguintes tarefas:
1. Ele recebe pela linha de comando uma expressão no formato
val1 op val2
onde op é uma operação (+, −, x ou X, /) e val1 e val2 são dois valores em ponto flutuante, NaN
ou ±∞.
2. Depois de receber a expressão seu programa deve realizar a operação op e mostrar o resultado
dela;
3. Seu programa também deve mostrar a configuração de bits das duas variáveis e do resultado. Tome cuidado com a endianness do seu proessador para que a saída seja apresentada
corretamente;
4. Seu programa também deve informar se alguma exceção do padrão IEEE-754 foi sinalizada
quando a operação foi feita. Use o registrador de status!
Por exemplo, seu programa poderia funionar assim:

```python
python3 caluleitor.py 21 / -0

Recebi 21.000000 / -0.000000 e resultado deu -inf
val1 = 0 10000011 01010000000000000000000 = 21
val2 = 1 00000000 00000000000000000000000 = -0
res = 1 11111111 00000000000000000000000 = -inf
Exceção FE_INEXACT: 0
Exceção FE_DIVBYZERO: 1
Exceção FE_UNDERFLOW: 0
Exceção FE_OVERFLOW: 0
Exceção FE_INVALID: 0
```
Atenção: faça este trabalho em C. Não faça em Python, não faça em Java. Aqui estão (apenas
alguns) motivos:
Da especifação da máquina virtual java:

<em>The floating-point operations of the Java Virtual Mahine do not throw
exceptions, trap, or otherwise signal the IEEE 754 exceptional conditions
of invalid operation, division by zero, overflow, underflow, or inexact.
The Java Virtual Mahine has no signaling NaN value.
</em>

Sobre Python: você pode ter alguma esperança usando numpy e numpy.seterr, mas vai estar
correndo riscos. A responsabilidade é toda sua e a chance de arrependimento é alta.

### Utilização

Para inicar o programa, basta executar o seguinte comando no terminal:

```bash
gcc -o ieee754 ieee754.c -lm 
```

Após o programa ser compilado, basta executar o seguinte comando no terminal:

```bash
./ieee754 val1 op val2
```

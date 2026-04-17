/*comando sql que liste as contas de um cliente:*/

select
	conta.NumConta, conta.saldo, conta.CPF, conta.CodAge
from
	conta, cliente
where
	cliente.CPF = conta.CPF
and
	cliente.nome = 'Christian Guilherme';
    
/*Comando SQL que liste as transações de um cliente cujos valores sejam maiores que 50.*/

select
	cliente.nome, movimentacao.tipo, movimentacao.quantia, movimentacao.data, movimentacao.hora
from
	cliente, conta, movimentacao
where
	cliente.CPF = conta.CPF
and
	conta.NumConta = movimentacao.NumConta
and
	movimentacao.quantia > 50
and
	cliente.nome = 'Christian Guilherme';

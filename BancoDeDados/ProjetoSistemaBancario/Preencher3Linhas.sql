/*Comandos sql que insiram 3 linhas em cada tabela:*/

insert into cliente
values ('12345678910', '121233133', 'Pedro da Silva', 'Rua ABC123', '41999999999','Casado'),
('78545856877', '745284629', 'Christian Guilherme', 'Rua Sofia 476', '77852655524','Solteiro'),
('74545412369', '568520455', 'Julia Rodriges', 'Rua Estados Unidos 76', '78541589960','Casado');

insert into agencia
values
(1, 'Agencia Quadrada', 'Rua Estudos 777', 'Rafael Ferreira'),
(2, 'Agencia Central', 'Av Principal 1000', 'Mariana Souza'),
(3, 'Agencia Norte', 'Rua das Flores 45', 'Carlos Lima');

insert into conta
values
(1, 350.00, '12345678910', 1),
(2, 1200.50, '78545856877', 2),
(3, 780.75, '74545412369', 3);

insert into movimentacao
Values
('credito', 200.00, '2026-03-30', '10:30:00', 1, 1),
('debito', 50.00, '2026-03-30', '14:20:00', 2, 2),
('credito', 100.00, '2026-03-31', '09:15:00', 3, 3);

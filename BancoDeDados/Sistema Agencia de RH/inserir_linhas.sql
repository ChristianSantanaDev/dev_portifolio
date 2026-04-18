/* 1- Inserir 3 linhas em cada tabela */
use agencia;
insert into empresa
values
(1, 'Hamburguers S.A', 'Rua da fonte preta 123', '1234567891012'),
(2, 'Atacado', 'Rua Flores cheirosas 476', '12547896354157'),
(3, 'Floricultura Verde', 'Rua da internet 41', '13285963941526');
INSERT INTO candidato
VALUES
(1, 'Cleomar Siveira Fruto', '15248753987', '15784536520', 'São José dos Pinhais'),
(2, 'Ana Souza', '98765432100', '41999999999', 'Curitiba'),
(3, 'João Silva', '12345678900', '41988888888', 'Colombo');
insert into vaga
values
(1, 1, 'Cozinha'),
(2, 2, 'Estoque'),
(3, 3, 'Atendimento');
insert into candidata_se
values
('2026-01-03', 'APROVADO', 2, 1),
('2026-04-12', 'PENDENTE', 1, 2),
('2026-03-29', 'REPROVADO', 3, 3);

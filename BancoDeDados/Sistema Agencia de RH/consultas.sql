/* 2-Listar os dados das vagas que possuem candidato cujo nome inicia com "Maria".*/
use agencia;
select
vaga.*
from
candidato, vaga, candidata_se
where
candidato.idCandidato = candidata_se.idCandidato
and
candidata_se.idVaga = vaga.idVaga
and
candidato.nome like 'Maria%';

/* 3-Listar as cidades dos candidatos que concorrem para as vagas da empresa com nome
"Empresa K". */
use agencia;
select
candidato.cidade
from
empresa, vaga, candidata_se, candidato
where
empresa.idEmpresa = vaga.idEmpresa
and
vaga.idVaga = candidata_se.idVaga
and
candidata_se.idCandidato = candidato.idCandidato
and
empresa.nome = 'Empresa K';

/* 3-Listar as vagas e os candidatos para o setor "Elétrico" */
use agencia;
select
vaga.*, candidato.nome
from
vaga, candidata_se, candidato
where
vaga.idVaga = candidata_se.idVaga
and
candidata_se.idCandidato = candidato.idCandidato
and
vaga.setor = 'Elétrico';

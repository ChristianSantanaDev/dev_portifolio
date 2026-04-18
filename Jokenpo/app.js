const botoes = document.querySelectorAll('.btn-jogada');
const res = document.querySelector('#mensagemResultado');
const placarjogador = document.querySelector("#placarJogador");
const placarcomputador = document.querySelector('#placarComputador');

const opcoes = ["Pedra", "Papel", "Tesoura"];

let pontosJogador = 0;
let pontosComputador = 0;

const jogar = (jogada) => {
    const indiceSorteado = Math.floor(Math.random()*3);
    const jogadaComputador = opcoes[indiceSorteado];

    //verificar quem ganhou
    if(jogada === jogadaComputador) {
        exibe_res(`Empate!! Ambos escolheram ${jogada}`, 'empate');
    } else if (
        (jogada === 'Pedra' && jogadaComputador === 'Tesoura') ||
        (jogada === 'Papel' && jogadaComputador === 'Pedra') ||
        (jogada === 'Tesoura' && jogadaComputador === 'Papel') 
    ) {
        exibe_res(`Vitória!! ${jogada} ganha de ${jogadaComputador}`, 'vitoria');
        pontosJogador++;
    } else {
        exibe_res(`Derrota!! ${jogada} perde para ${jogadaComputador}`, 'derrota');
        pontosComputador++;
    }
    placarjogador.textContent = pontosJogador;
    placarcomputador.textContent = pontosComputador;
}

const exibe_res = (mensagem, final) => {
    res.textContent = mensagem;
    res.className = `resultado ${final}`;
}

botoes.forEach((botao) => {
    botao.addEventListener('click', (evento) => {

        const jogadaEscolhida = evento.currentTarget.getAttribute('data-jogada');
        jogar(jogadaEscolhida);

    });
});
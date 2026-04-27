const op1 = document.querySelector(".op1");
const op2 = document.querySelector(".op2");
const sn = document.querySelector(".sn");
const btns = document.querySelectorAll(".btn-res");


const resp = document.querySelector(".resposta");

let resposta = 0;
let botao_sorteado = 0;

function gerar_quiz(){
    //limpando da jogada anterior
    btns.forEach((botao) => {botao.disabled = false});
    resp.innerHTML = "";
    //-------------------------------------------------
    let operando1 = Math.floor(Math.random()*100)+1;
    let operando2 = Math.floor(Math.random()*100)+1;
    let sinais = ['+', '-'];
    let sinal = sinais[Math.floor(Math.random()*sinais.length)];

    if(sinal === "+") resposta = operando1+operando2;
    if(sinal === "-") resposta = operando1-operando2;
    
    op1.innerHTML = operando1;
    op2.innerHTML = operando2;
    sn.innerHTML = sinal;

    botao_sorteado = Math.floor(Math.random()*4)+1;

    btns.forEach((botao) => {
        const idBotao = parseInt(botao.getAttribute("data-botao"));

        if(idBotao === botao_sorteado){
            botao.textContent = resposta;
        } else {
            resposta123 = Math.floor(Math.random()*100)+1;
            if(resposta123 === resposta){
                botao.textContent = `${(Math.floor(Math.random()*20)+1)+resposta}`;
            } else {
                botao.textContent = resposta123;
            }
            
        }

    });



}

function verificar_resposta(btn) {
    if(btn === botao_sorteado){
        resp.textContent = "Resposta certa!";
        resp.style.color = "green";
    } else {
        resp.textContent = "Resposta errada";
        resp.style.color = "red";
    }
}

btns.forEach((botao) => {
    botao.addEventListener("click", (evento) => {
        const data = parseInt(evento.currentTarget.getAttribute("data-botao"));
        verificar_resposta(data);
        
        btns.forEach((botao) => {botao.disabled = true});

        setTimeout(() => {
            gerar_quiz();
        }, 2500);

         
    });
});

gerar_quiz();

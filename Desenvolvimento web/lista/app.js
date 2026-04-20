const btn = document.querySelector("#btn-adicionar");
const lista = document.querySelector("#lista");
const input = document.querySelector("#input1");
const carde = document.querySelector(".card");


let qual = 1;
let altura = 200;
const quantoaumentar = 70;
carde.style.height = `${altura}px`;



btn.addEventListener('click', (evento) => {
    if(input.value === ""){
        alert("Digite Alguma coisa!");
    } else {
    const novatarefa = document.createElement("li");
    const botaoexcluir = document.createElement("button");
    

    botaoexcluir.textContent = `Excluir ${qual}° tarefa`;
    botaoexcluir.id = `btn-excluir-${qual}`;
    botaoexcluir.dataset.qual = qual;

    novatarefa.textContent = input.value;
    novatarefa.id = `tarefa-${qual}`;
    qual++;

    lista.appendChild(novatarefa);
    lista.appendChild(botaoexcluir);

    input.value = "";

    altura+=quantoaumentar;
    
    carde.style.height = `${altura}px`;

   botaoexcluir.addEventListener('click', (evento) => {
        novatarefa.remove();
        botaoexcluir.remove();
        altura-=quantoaumentar;
    
        carde.style.height = `${altura}px`;
   });

   novatarefa.addEventListener('click', (e) => {
       novatarefa.classList.toggle("concluida");

   });
    }
});


input.addEventListener('keydown', (e) => {
    if(e.key === "Enter") {
        btn.click();
    }
});







// Declaração da licença sob a qual o contrato é distribuído
// SPDX-License-Identifier: GPL-3.0

// Indica a versão mínima do compilador Solidity necessária para compilar o contrato
pragma solidity ^0.8.0;

// Declaração do contrato chamado Anac
contract Anac {

    // Variável de estado para armazenar a idade
    uint age;

    // Variável de estado para armazenar o endereço do proprietário, declarada como privada
    address private owner;

    // Construtor do contrato, executado uma vez no momento da criação
    constructor() {
        // Define o remetente do contrato como o proprietário
        owner = msg.sender;
        // Inicializa a idade como 18
        age = 18;
    }

    // Modificador para restringir o acesso a certas funções apenas ao proprietário
    modifier onlyOwner() {
        // Verifica se o remetente da transação é o proprietário
        require(isOwner(), "You need to be the owner to execute this");
        // Continua com a execução da função se o requisito for atendido
        _;
    }

    // Função pública para retornar o endereço do proprietário
    function getOwner() public view returns (address) {
        return owner;
    }

    // Função pública para verificar se o remetente da chamada da função é o proprietário
    function isOwner() public view returns (bool) {
        return (owner == msg.sender);
    }

    // Função pública para permitir que o proprietário defina a idade
    function setAge(uint _age) public onlyOwner {
        // Define a idade com o valor fornecido
        age = _age;
    }

    // Função pública para retornar a idade armazenada
    function getAge() public view returns (uint) {
        return age;
    }
}
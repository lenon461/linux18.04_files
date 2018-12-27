pragma solidity ^0.4.11;

//0xE58D964DB8a6321C2149c5A9670e825e631922E9

contract voteContract {

    mapping(address => bool) voters;
    mapping(string => uint) candidates;
    mapping(uint8 => string) candidateList;

    uint8 numberOfCandidates;
    address contractOwner;

    function voteContract(){
        contractOwner = msg.sender;
    }

    function addCandidate(string cand){
        bool add = true;
        for(uint8 i = 0; i < numberOfCandidates; i++){
            if(sha3(candidateList[i]) == sha3(cand)){
                add = false; break;
            }
        }
        if(add){
            candidateList[numberOfCandidates] = cand;
            numberOfCandidates++;
        }
    }

    function vote(string cand){
        if(voters[msg.sender]){}
        else{
            voters[msg.sender] = true;
            candidates[cand]++;
        }
    }

    function alreadyVoted() constant returns(bool){
        if(voters[msg.sender])
            return true;
        else
            return false;

    }

    function getNumOfCandidates() constant returns(uint8){
        return numberOfCandidates;
    }

    function getCandidateString(uint8 number) constant returns(string){
        return candidateList[number];
    }

    function getScore(string cand) constant returns(uint){
        return candidates[cand];
    }

    function killContract(){
        if(contractOwner == msg.sender){
            selfdestruct(contractOwner);
        }
    }







}

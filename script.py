import subprocess

def executePrgrm(executable_path):
    # Comando para executar o programa
    command = [executable_path]

    try:
        # Executa o programa
        
        # Cria um novo processo, redireciona a saída para o processo python
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE) 
        stdout, stderr = process.communicate()

        # Arpresentação de erro
        if process.returncode != 0:
            print('Erro ao executar o programa')
        else:
            print('Programa executado com sucesso')
        
        # Retorna a saída do programa
        return stdout.decode(), stderr.decode()
    
    except Exception as e:
        # Apresenta o erro
        print(f"Erro:{e}")
        return None, None

def analyzeFlop():
    # Chamar o likwid para a análise de FLOP
    # [comando likwid,  -C e 0 (especifica o núcleo 0), -g e FLOPS_DP (especifica a métrica de FLOP), -m (ativa a medição), -O (otimiza a contagem de eventos), -- (separador final)]
    command = ["likwid-perfctr", "-C", "0", "-g", "FLOPS_DP", "-m", "-O", "--"]

    try:
        # Executando o comando do Likwid
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate()

        # Verifica se ocorreu algum erro durante a execução
        if process.returncode != 0:
            print(f"Erro ao executar o Likwid para análise de FLOP: {stderr.decode()}")
        else:
            print("Análise de FLOP realizada!")

        return stdout.decode(), stderr.decode()

    except Exception as e:
        print(f"Erro: {e}")
        return None, None
        
if __name__ == "__main__":
    # Caminho do executável
    executable_path = "./perfSL"

    # Executa o programa
    stdout, stderr = executePrgrm(executable_path)

    # Faz a análise de FLOP
    stdout, stderr = analyzeFlop()

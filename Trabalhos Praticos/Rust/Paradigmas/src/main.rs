use crossterm::execute;
use crossterm::terminal::{Clear, ClearType};
use std::collections::HashMap;
use std::fs;
use std::io;

fn clear_terminal() {
    execute!(io::stdout(), Clear(ClearType::All)).unwrap();
}

fn main() {
    let mut tentativas_easy = 0;
    let mut tentativas_normal = 0;
    let mut tentativas_dificil = 0;
    let mut tentativas_impossivel = 0;

    let mut acerto_easy = 0;
    let mut acerto_normal = 0;
    let mut acerto_dificil = 0;
    let mut acerto_impossivel = 0;

    let file_content = fs::read_to_string("frases.txt").expect("Erro ao ler o arquivo");
    let lines: Vec<&str> = file_content.lines().collect();
    let mut phrase_map: HashMap<char, String> = HashMap::new();
    for (index, ch) in ('a'..='z').enumerate() {
        if let Some(line) = lines.get(index) {
            phrase_map.insert(ch, line.to_string());
        }
    }

    loop {
        clear_terminal();
        println!("Bem-vindo ao Desafio de Criptografia!");
        println!("Escolha uma opção:");
        println!("1. Fácil");
        println!("2. Normal");
        println!("3. Difícil");
        println!("4. Impossível");

        let mut choice = String::new();
        io::stdin().read_line(&mut choice).expect("Erro ao ler a entrada");
        let choice: usize = match choice.trim().parse() {
            Ok(num) if num >= 1 && num <= 4 => num,
            _ => {
                continue;
            }
        };

        match choice {
            1 => {
                    println!("Esse desafio possui {} tentativas e {} acertos.", tentativas_easy, acerto_easy);
                    println!("\n");
                    tentativas_easy += 1;
                    let easy_word = "reverso";
                    let encrypted = easy_word.chars().rev().collect::<String>();
                    println!("Dica: Tente analisar a palavra a partir de outra perspectiva.\n");
                    println!("Palavra criptografada: {}", encrypted);
                    println!();
                    println!("Tente acertar a palavra:");
                    let mut input = String::new();
                    io::stdin().read_line(&mut input).expect("Erro ao ler a entrada");
                    let input = input.trim();
                    println!("\n");
                    if input == easy_word {
                        println!("Parabéns, você acertou!");
                        acerto_easy += 1;
                    } else {
                        println!("Palavra Incorreta, tente novamente.");
                    }
                }
            2 => {
                println!("Esse desafio possui {} tentativas e {} acertos.", tentativas_normal, acerto_normal);
                println!("\n");
                println!("Dica: Uma das cifras mais conhecidas.\n");
                tentativas_normal += 1;
                let normal_word = "graydon";
                let shift: u8 = 3;
                let mut encrypted = String::new();
                for c in normal_word.chars() {
                    if c.is_alphabetic() {
                        let base = if c.is_ascii_lowercase() { b'a' } else { b'A' };
                        let shifted = ((c as u8 - base + shift) % 26) + base;
                        encrypted.push(shifted as char);
                    } else {
                        encrypted.push(c);
                    }
                }
                println!("Palavra criptografada: {}", encrypted);
                println!("Tente acertar a palavra:");
                let mut input = String::new();
                io::stdin().read_line(&mut input).expect("Erro ao ler a entrada");
                let input = input.trim();
                println!("\n");
                if input == normal_word {
                    println!("Parabéns, você acertou!");
                    acerto_normal += 1;
                } else {
                    println!("Palavra Incorreta, tente novamente.");
                }
            }
            3 => {
                println!("Esse desafio possui {} tentativas e {} acertos.", tentativas_dificil, acerto_dificil);
                println!("\n");
                println!("Dica: Esta cifra utiliza uma chave e ela é secreta.\n");
                tentativas_dificil += 1;
                let hard_word = "vigenere";
                let key = "secreta";
                let mut encrypted = String::new();
                let key_len = key.len();
                for (i, c) in hard_word.chars().enumerate() {
                    if c.is_ascii_lowercase() {
                        let key_char = key.chars().nth(i % key_len).unwrap();
                        let x = (c as u8 - b'a') + (key_char as u8 - b'a');
                        let x = x % 26 + b'a';
                        encrypted.push(x as char);
                    } else {
                        encrypted.push(c);
                    }
                }
                println!("Palavra criptografada: {}", encrypted);
                println!();
                println!("Tente acertar a palavra:");
                let mut input = String::new();
                io::stdin().read_line(&mut input).expect("Erro ao ler a entrada");
                let input = input.trim();
                println!("\n");
                if input == hard_word {
                    println!("Parabéns, você acertou!");
                    acerto_dificil += 1;
                } else {
                    println!("Palavra Incorreta, tente novamente.");
                }
            }

            4 => {
                println!("Esse desafio possui {} tentativas e {} acertos.", tentativas_impossivel, acerto_impossivel);
                println!("\n");
                tentativas_impossivel += 1;
                let impossible_word = "hamlet";
                let mut tentativas = 3;
                for c in impossible_word.chars() {
                    let c_lower = c.to_ascii_lowercase();
                    if let Some(phrase) = phrase_map.get(&c_lower) {
                        print!("{} ", phrase);
                    }
                }
                println!("\n");
                while tentativas > 0 {
                    println!("Você possui {} tentativas.", tentativas);
                    println!("Tente acertar a palavra:");
                    let mut input = String::new();
                    io::stdin().read_line(&mut input).expect("Erro ao ler a entrada");
                    let input = input.trim();
                    println!("\n");
                    for c in input.chars() {
                        let c_lower = c.to_ascii_lowercase();
                        if let Some(phrase) = phrase_map.get(&c_lower) {
                            print!("{} ", phrase);
                        }
                    }
                    println!("\n");
                    if input == impossible_word {
                        acerto_impossivel += 1;
                        println!("Parabéns! Você acertou a palavra!");
                        break;
                    } else {
                        println!("Tentativa incorreta.");
                    }
                    tentativas -= 1;
                }
            }

            _ => {
                println!("Opção inválida. Encerrando...");
                break;
            }
        }

        println!("Pressione Enter para continuar...");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Erro ao ler a entrada");
    }
}

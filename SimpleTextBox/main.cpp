#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

class SimpleTextBox
{
	char _text[5001];
	size_t size;

public:
	SimpleTextBox()
	{
		size = 0;
		_text[size] = '\0';
	}
	
	/* ************ APPEND ****************
		adicionar sempre a seguir: 0,1,2,3...  */
	bool append(char ap) 
	{
		for (size_t i = 0; i < 5001; i++) 
		{
			if (_text[i] == '\0') 
			{
				_text[i] = ap;
				_text[i+1] = '\0';
				cout << ap;
				++size;	// aumentar o tamanho para o acertar o charCount.
				return true;
			}
		}
		return false;
	}
	
	/* ************ REMOVE ****************
		Apaga e shift para a esquerda.	
		Exemplo:
		Se quiseremos remover na posi��o = 6, as posi��es 7 8 e 9 passam a ser 6 7 e 8,
		e o que estava na posi��o 7 passa a estar na posi��o 6, e assim sucessivamente para os numeros que se encontravam � frente da psoi��o.		*/
	void remove(size_t size)  
	{
		if (size != 0) 
		{
			size--; // diminuir o tamanho para acertar o charCount.
			while (_text[size - 1] != '\0')
			{
				_text[size] = _text[size + 1];
				size++;
			} 
		}
	}

	/*  ************ INSERT ****************
			Usando a mesma logica que o remove, s� que em vez de fazer um shift para a esq. faz-se para a direita, que por conseguinte abre um espa�o.
		i.e., shift � direita de todos os elementos que est�o na posi��o onde queremos inserir.
		Exemplo:
			Se quiseremos inserir na posi��o = 6, as posi��es 7 8 e 9 passam a ser 8 9 e 10,
		e o que estava na posi��o 6 passa a estar na posi��o 7, ap�s isso mete-se o que queremos na pos. 6, que j� ficou livre.					*/
	bool insert(char new_char, size_t pos) 
	{									   
		for (int i = 0; i < size; i++)     
		{								  
			if (i == pos)				   
			{
				for (int j = ++size; j > i; j--) 
				{
					_text[j] = _text[j - 1];
				}
				i++;
				_text[pos] = new_char;
				++size;
				return true;
			}
		}
		return false;
	}

	/*	************ CONTA CARACTERES ****************	
	O tamanho da caixa de texto � o mesmo que o nr de palavras.		*/
	size_t charCount() const
	{
		return size;
	}
	
	/*	************ CONTA PALAVRAS ****************
	Separado por espa�os, ou pontos, ou enter significa + uma palavra.		*/	
	size_t wordCount() const
	{
		int contaPalavras = 0;

		for (size_t i = 0; i < (sizeof(_text)); i++)
		{
			if (_text[i]==' ' || _text[i]=='.' || _text[i]=='\n')
			{
				++contaPalavras;
			}
		}
		return contaPalavras;
	}
	
	/*		************ CONTA FRASES ****************
		Cada ponto('.') ou enter, significa + uma frase.				*/	
	size_t sentenceCount() const
	{
		int contaLinhas = 0;

		for (size_t i = 0; i < (sizeof(_text)); i++)
		{
			if (_text[i] == '\n' ||  _text[i] == '.') 
			{
				++contaLinhas;
			}
		}
		return contaLinhas;
	}
	
	string text() 
	{
		_text[size] = '\0';
		string s = _text;
		return s;
	}

};

int main()
{
	SimpleTextBox ec;

	ec.append('a');
	ec.append('t');
	ec.append('c');
	ec.append('2');
	ec.append('.');
	

	ec.append('a');
	ec.append('t');
	ec.append('c');
	ec.append('2');
	ec.append(' ');
	

	ec.append('a');
	ec.append('t');
	ec.append('c');
	ec.append('2');
	ec.append('.');
	
	cout << endl;
	ec.remove(2);

	cout << endl;
	cout << ec.wordCount() << " words" << endl;

	cout << endl;
	cout << ec.charCount() << " chars" << endl;

	cout << endl;
	cout << ec.sentenceCount() << " sentences" << endl;

	cout << endl;
	cout << ec.insert('W', 2);
	cout << ec.insert('W', 50);
	cout << ec.insert('Y', 7) << endl;

	cout << endl;
	string str = ec.text();
	cout << str << endl;
}
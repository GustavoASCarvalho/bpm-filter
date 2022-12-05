<div id="top"></div>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<!-- [![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url] -->

[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <h1 align="center">Adicionando filtro em imagens BPM</h1>
</div>

## Começando

Este é um exemplo de como você pode configurar e rodar seu projeto localmente.
Para conseguir rodar em sua maquina, siga os passos abaixo.

### Pré-requisitos

- [clang](https://clang.llvm.org/)

### Instalação

1. Clone o repositório
   ```sh
   git clone https://github.com/GustavoASCarvalho/filter-in-c.git
   ```
2. Compile o código em C
   ```sh
   clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o filter filter.c helpers.c
   ```
3. Execute o código
   ```sh
   ./filter -r images/courtyard.bmp out.bmp
   ```
4. Template
   ```sh
   ./filter -{b: blur; g: grayscale; r: rotate, e: edge; } { caminho da imagem } out.bmp
   ```

<p align="right">(<a href="#top">voltar ao topo</a>)</p>

[contributors-shield]: https://img.shields.io/github/contributors/GustavoASCarvalho/Acervo.svg?style=for-the-badge
[contributors-url]: https://github.com/GustavoASCarvalho/Acervo/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/GustavoASCarvalho/Acervo.svg?style=for-the-badge
[forks-url]: https://github.com/GustavoASCarvalho/Acervo/network/members
[stars-shield]: https://img.shields.io/github/stars/GustavoASCarvalho/Acervo.svg?style=for-the-badge
[stars-url]: https://github.com/GustavoASCarvalho/Acervo/stargazers
[issues-shield]: https://img.shields.io/github/issues/GustavoASCarvalho/Acervo.svg?style=for-the-badge
[issues-url]: https://github.com/GustavoASCarvalho/Acervo/issues
[license-shield]: https://img.shields.io/github/license/GustavoASCarvalho/Acervo.svg?style=for-the-badge
[license-url]: https://github.com/GustavoASCarvalho/front-angular-acervo/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/gustavoascarvalho
[product-screenshot]: resources/images/screencapture.png

>**Ejercicio 1:** _Calcula los límites de las sucesiones_
>
> 1.a)
> $$
> x_n = \left(1+\log \left(\frac{n^2+1}{n^2+n+1} \right) \right)^n \\= \left(1+ \log(1-\frac{n}{n^2+n+1}\right)^n \sim \left(1-\frac{n}{n^"+n+1} \right)^n \to e ^L
> $$
> $$
> L = \lim_{n \to \infty}\left\{\frac{-n^2}{n^2+n+1}\right\} = -1 \\ {x_n} \to e^{-1} = \frac{1}{e}
> $$
>
> 1.b)
> $$
> y_n = \frac{1^ 3 + 3 ^ 3 + 5 ^ 3 + \dots + (2n-1) ^ 3}{n^4} = \frac {a_n}{b_n} \to L ;
> \frac{a_{n+1}-a_n}{b_{n+1}-b_n} \to L; \\
  \frac{(2(n+1))-1)^3}{(n+1) ^4 -n ^4} = \frac{(2n+1) ^3}{4n ^3 + 6n ^2 + 4n + 1 }= \frac{8n ^3+12n  ^2 + 6n +1}{4n ^3 + 6n ^2 + 4n + 1 } \to 2; \\
  {y_n \to 2}
> $$

>**Ejercicio 2:** _Estudia la convergencia absoluta y la convergencia de las siguientes series:_
>
> 2. a)
>
>$$
\sum_{n \ge 1} \frac{5 ^n n!}{\sqrt[4]{n} · 9 · 14·19 \dots (4+5n)};$$
>Para esta serie no es necesario estudiar la convergencia absoluta porque no tiene términos negativos.
>$$
\frac{5 ^{n +1}(n+1)!}{\sqrt[4]{n+1}·9·14·19 \dots (9+5n)} \cdot \frac{\sqrt[4]{n}·9·14·19 \dots (4+5n)}{5 ^n n!} =
\\ \frac{5(n+1)}{9+5n}\cdot \sqrt[4]{\frac{n}{n+1}}\to 1;
>$$
>    
>    Tiende a uno por la izquierda, por tanto necesitamos más información. Aplicamos el criterio de Raabe:
>> Supongamos $a_n \gt 0$ para todo $n \in \mathbb{N}$, y pongamos $R_n=n\left(1-\frac{a_{n+1}}{a_n}\right)$. Supongamos que $\lim{R_n}= L \in \mathbb{R}\space \cup \{-\infty,+\infty\}$: Entonces:
>>
>>i) Si $L\gt 1$ o $L=+\infty$, la serie $\sum_{n\ge1}a_n$ es convergente.
>>
>>ii) Si $L \lt 1$ o $L=-\infty$ o si existe un $k \in\mathbb{N}$ tal que $R_n \le 1$ para todo $n \ge k$, entonces la serie $\sum_{n\ge1}a_n$ es divergente.
>    
>$$
n\left( 1- \frac{5(n+1)}{5(n+9)}\cdot\sqrt[4]{\frac{n}{n+1}} \right) = \left(\frac{5(n+1)}{5n+9}\cdot\sqrt[4]\frac{n}{n+1}\right) ^{-n} = \left(\frac{5n+9}{5(n+1)}\cdot\sqrt[4]\frac{n+1}{n}\right) ^n  \\ \sqrt[4]{\frac{n+1}{n}} \to e ^{\frac{1}{4}}; \\ x_n ^{y_n} \to e ^L \Leftrightarrow y_n(x_n -1 )
\to L \\ \left(\frac{5n+9}{5n+5}\right) ^n = \left(1  + \frac{4}{5n+5}\right) ^n \to e ^L \Leftrightarrow n\left(\frac{4}{5n+5}\right) \to \frac{4}{5}; \\
e ^{\frac{4}{5}}\cdot e ^{\frac{1}{4}} = e ^ {\frac{21}{20}} > 1;
>$$
>    
>    Según el criterio de Raabe la serie converge.
>
> 2.b)
>$$
\sum_{n \ge 1}(-1)^{n+1}\left(\sqrt[3]{n+1}-\sqrt[3]{n}\right);
>$$
>> Aplicamos el criterio de Leibniz:
>Dada una serie alternada $\sum_{n \ge 1}(-1)^{n+1}a_n$, converge si $\{a_n\}$ es decreciente y $\{a_n\} \to 0$
>$$
a_n = \sqrt[3]{n+1}-\sqrt[3]{n} = \sqrt[3]{n+1}\left(1-\frac{\sqrt[3]{n}}{\sqrt[3]{n+1}}\right) = \sqrt[3]{n+1}\left(1-\sqrt[3]{\frac{n}{n+1}}\right)
>$$
>Sea $f: \mathbb{R}\to\mathbb{R}$ tal que $f(x) = \sqrt[3]{x+1}\left(1-\sqrt[3]{\frac{x}{x+1}}\right)$ Se tiene que:
>$$\lim_{x\to +\infty }f(x)\to L \implies \lim_{x\to+\infty}a_n = L$$
>
>Calculamos $\lim_{x\to+\infty}f(x)$:
>$$
\lim_{x\to+\infty}\sqrt[3]{x+1} \left( 1- \sqrt[3]{\frac{x}{x+1}} \right)  = \lim_{x\to+\infty}\frac{1-\sqrt[3]{\frac{x}{x+1}}}{\sqrt[3]{x+1}} = \\ \mathrm{(L'Hôpital)}\\ = \lim_{x\to+\infty}\frac{1}{x^{2/3}(x+1)^{2/3}} = 0 \implies \{a_n\}\to 0
>$$
> Se verifica el criterio de Leibniz, así que la serie estudiada converge. Ahora nos centramos en la convergencia absoluta. Para ello estudiamos
$$\sum_{n\ge1}\left|(-1)^{n+1}\left(\sqrt[3]{n+1}-\sqrt[3]{n}\right)\right|= \sum_{n \ge 1}\left(\sqrt[3]{n+1}-\sqrt[3]{n}\right); $$
Comenzamos manipulando $a_n =\sqrt[3]{n+1}-\sqrt[3]{n}$
>
>$$
\sqrt[3]{n+1} - \sqrt[3]{n}= \sqrt[3]{n}\left(\sqrt[3]{1+\frac{1}{n}}-1\right)
>$$
>Sea $x_n=\frac{1}{n}$ aplicamos la equivalencia asintótica $(1+x_n)^\alpha-1\sim \alpha x_n$, ya que $x_n = \frac{1}{n} \to 0$
>
>$$
\sqrt[3]{n}\left[\left(1+\frac{1}{n}\right)^{\frac{1}{3}}-1\right] \sim n^{\frac{1}{3}}\cdot \frac{1}{3}\cdot\frac{1}{n} = \frac{n^{1/3}}{n}\cdot \frac{1}{3} = \frac{1}{3n^{2/3}}
>$$
>Comparamos esta serie con una serie de Rienman de la formma $\frac{1}{n^\alpha}$, en este caso $\alpha = \frac{2}{3} \lt 1$ por lo tanto la serie no converge. Concluimos que la serie no es absolutamente convergente.

>3) Sea $f: \mathbb{R}\to \mathbb{R}$ una función continua y creciente. Prueba que para todo conjunto acotado y no vacío, $A\subset \mathbb{R}$, se verifica que $\sup f(A) = f(\sup A)$.
>
>Definamos $\alpha = \sup A$, entonces $\sup f(A) = f(\alpha)$.
>
>Sabemos que $f(n) \ge f(m) \Leftrightarrow n \ge m$, por ser $f$ creciente. Además, por ser $\alpha = \sup A$, tenemos que $\alpha \ge a,\space \forall a \in A$ así que nos queda que $f(\alpha) \ge f(a), \space \forall a \in A$ que equivale a decir que $f(\alpha) = \sup f(A)$ como se pedía.


# Z Buffer in 1D (a.k.a. `z_buffer_1d.c`)

## Prove the lower bound time complexity

The lower bound time complexity of Z Buffer in 1D is `O(n log(n))`

Resource
1.  Prove the lower bound of sorting algorithm
*   https://youtu.be/WffUZk1pgXE?si=XinBcXM96UDfOyAq

# Calculating the angle and projection of 2 vectors

The Law of Cosine is used for finding the angle between 2 vector `v`, and `u`. Where 
*	`B = |v|`
*	`A = |u|`
*	`C = |u-v|`

Prove the Law of Cosine
*	`B = b_1 + b_2`
*	`A^2 = b_1^2 + d^2 = cos(t)^2 * A^2 + sin(t)^2 * A^2`
*	`C^2 = b_2^2 + d^2 = (B - cos(t) * A)^2 + sin(t)^2 * A^2 = B^2 - 2AB * cos(t) + cos(t)^2 * A^2 + sin(t)^2 * A^2`
*	`C^2 - A^2 = B^2 - 2AB * cos(t)`
*	`C^2 = A^2 + B^2 - 2AB * cos(t)`

We can find the angle between `v` and `u` by
*	`C^2 = A^2 + B^2 - 2AB * cos(t)`
*	`C^2 - A^2 - B^2 = - 2AB * cos(t)`
*	`A^2 + B^2 - C^2 = 2AB * cos(t)`
*	`(A^2 + B^2 - C^2) / (2AB) = cos(t)`
*	`(u_0^2+... + v_0^2+... - (u_0 - v_0)^2+...) / (2AB) = cos(t)`
*	`(u_0^2+... + v_0^2+... - (u_0^2 - 2 u_0 v_0 + v_0^2)+...) / (2AB) = cos(t)`
*	`(u_0^2+... + v_0^2+... + (- u_0^2 + 2 u_0 v_0 - v_0^2)+...) / (2AB) = cos(t)`
*	`(2 u_0 v_0 +...) / (2AB) = cos(t)`
*	`cos(t) = 2uv / (2|u||v|)`
*	`cos(t) = uv / (|u||v|)`

We can apply the law of cosine to computing the 1D projection of `u` on `span(v)`
*	`w = (cos(t) * A)(1 / |v|)v`
*	`w = (cos(t) * |u|)(1 / |v|)v`
*	`w = (uv / |v|)(1 / |v|)v`
*	`w = (uv / |v|^2)v`

Resource
1.	1D Projection visualization on Desmos
*	https://www.desmos.com/calculator/y7wcdu8puz

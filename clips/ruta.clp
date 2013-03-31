(deftemplate nodo
(slot desde)
(slot hacia)
(slot costo))

(deftemplate objetivo
	(slot desde)
	(slot hacia)
        (slot costo))

(deffacts datos
	(nodo (desde a) (hacia b) (costo 2))
	(nodo (desde a) (hacia c) (costo 3))
	(nodo (desde b) (hacia c) (costo 4))
	(nodo (desde b) (hacia d) (costo 3))
	(nodo (desde c) (hacia e) (costo 2))
	(nodo (desde c) (hacia d) (costo 3))
	(nodo (desde e) (hacia d) (costo 1))
	(nodo (desde d) (hacia f) (costo 4))
	(nodo (desde e) (hacia f) (costo 3))
	(objetivo (desde a)(hacia f) (costo 0))
	(distancia 1000))

(defrule ruta
	?obj <-(objetivo (desde ?desde)(hacia ?haciaf)(costo ?rutacosto))
	(nodo (desde ?desde)(hacia ?hacia)(costo ?costo))
=>
	
	(bind ?suma (+ ?rutacosto ?costo))
	(assert (objetivo (desde ?hacia)(hacia ?haciaf) (costo ?suma)))
)

(defrule fin
	?obj <-(objetivo (desde ?desde)(hacia ?desde) (costo ?costo))
	?dis <-(distancia ?dist)
=>
	(bind ?mini(min ?dist ?costo))
	(retract ?obj ?dis)
	(assert (distancia ?mini))
)

(defrule fin_print
	?dis <-(distancia ?dist)
	=>
	(printout t "La ruta minima es " ?dist crlf)
)


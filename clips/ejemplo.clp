(deftemplate alumno
  (slot nombre)
  (slot edad)
  (slot nota)
  (slot saldo)
)

(deffacts datos
   (alumno (nombre "wilber")(edad 21)(nota 17) (saldo 0))
)

(defrule inicio
  =>
  (assert (menu))
)
(defrule menu
  ?men <-(menu)
  =>
  (retract ?men)
  (printout t "1.Ingresar" crlf)
  (printout t "2.Visualizar" crlf)
  (printout t "3.buscar " crlf)
  (printout t "4.Eliminar " crlf)
  (printout t "5.Maximo " crlf)
  (printout t "6.Salir " crlf )
  (printout t "Eliga una opcion" crlf)
  (assert (opcion (read)))
)
(assert (menu))


(defrule maximo
   ?op <-(opcion ?opc)
  (test (eq ?opc 5))
   =>
   (retract ?op)
   (assert (maxi 0))
)

(defrule maxi_nota
   ?op <- (maxi ?maxi)
   (alumno (nombre ?nombre)(edad ?edad)(nota ?nota)(saldo ?saldo))
   (test (> ?nota ?maxi))
   =>
   (retract ?op)
   (assert (maxi ?nota) )
)

(defrule maxi_nota_print
   ?op <- (maxi ?maxi)
   =>
   (retract ?op)
   (printout t "La maxima nota es " ?maxi crlf)
   (assert (menu))
)


(defrule ingresar
  ?op <-(opcion ?opc)
  (test (eq ?opc 1))
  =>
  (retract ?op)
  (printout t "Ingrese el nombre" crlf)
  (bind ?nombre(read))
  (printout t "Ingrese la edad " crlf)
  (bind ?edad(read))
  (printout t "ingrese nota" crlf )
  (bind ?nota(read))
  (printout t "ingrese saldo" crlf)
  (bind ?saldo(read))
  (assert(alumno (nombre ?nombre)(edad ?edad)(nota ?nota)(saldo ?saldo)))
  (assert (menu))
)
(defrule visualizar
  ?op <- (opcion ?opc)
  (test (eq ?opc 2))
  =>
  (retract ?op)
  (facts)
  (assert (menu))
)

(defrule salir 
  ?op <-(opcion ?opc)
  (test (eq ?opc 5))
  =>
  (retract ?op)
  (exit)
)

(defrule buscar
  ?op <-(opcion ?opc)
  (test (eq ?opc 3))
  =>
  (retract ?op)
  (printout t "ingrese el nombre a  buscar " crlf)
  (assert (buscar (read)))
)

(defrule buscar_Nombre
  ?bus <-(buscar ?nombre)
  (alumno (nombre ?nombre)(edad ?edad)(nota ?nota)(saldo ?saldo))
  =>
  (retract ?bus)
  (printout t ?nombre "tiene" ?edad "con nota " ?nota  "total saldo" ?saldo crlf)
  (assert (menu))
)

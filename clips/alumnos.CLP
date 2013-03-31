(deftemplate alumno
	(slot nombre)
	(slot nota)		
)

(defrule inicio
=>
  (assert (menus))
)

(defrule menus
	?men <- (menus)
    =>
    (retract ?men)
    (printout t "1. Ingresar " crlf)
    (printout t "2. Visualizar " crlf)
    (printout t "3. Buscar " crlf)
    (printout t "4. Eliminar " crlf)
    (printout t "5. Salir " crlf)
    (printout t "Ingrese su opcion " crlf)
    (assert (opcion (read) ))
)

(defrule ingresar
	?op <- (opcion ?opc)
	(test (eq ?opc 1))
	=>
	(retract ?op)
	(printout t "Ingrese el nombre " crlf)
	(bind ?nombre(read))
	(printout t "Ingrese la nota " crlf)
	(bind ?nota(read))
	(assert(alumno (nombre ?nombre) (nota ?nota)))
	(assert(menu))
)

(deffacts datos
	(alumno (nombre "Tania") (nota 14))
	(alumno (nombre "Malu") (nota 10))
	(alumno (nombre "Wilber") (nota 15))
)

(defrule vizualizar_aprobados
	(alumno (nombre ?nombre) (nota ?nota))
	(test (> ?nota 10))
	=>
	(printout t ?nombre "Aprobada" crlf)
)

(defrule buscar
	?op <- (opcion ?opc)
	(test (eq ?opc 3))
 	=>
	(printout t "Ingrese el nombre a buscar " crlf)
	(assert (busca (read)))
)

(defrule encontrado
	?bus <- (busca ?nombre)
	(alumno (nombre ?nombre) (nota ?nota))
	=>
	(retract ?bus)
	(printout t ?nombre " tiene nota " ?nota crlf)
	(assert (menus))
)

(defrule no_encontrado
	?bus <- (busca ?nombre)
	=>
	(retract ?bus)
	(printout t " no encontrado " )
	(assert (menus))
)

(defrule buscar_nombre
	?bus <- (busca ?nombre)
	(alumno (nombre ?nombre) (nota ?nota))
	=>
	(retract ?bus)
	(printout t ?nombre " tiene nota " ?nota crlf)
	(assert (menus))
)

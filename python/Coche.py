class Coche:
	def __init__(self,gas):
		self.gas=gas
		print "Tenemos ",gas," de gas"
	def arrancar(self):
		if self.gas>0:
			print "Arranca"
		else:
			print "No Arranca"
	def conducir(self):
		if(self.gas>0):
			self.gas-=1
			print "Quedan ",self.gas," de gas"
		else:
			print "No se mueve"


mi_coche=Coche(3)
mi_coche.arrancar()
mi_coche.conducir()
mi_coche.conducir()
mi_coche.conducir()
mi_coche.conducir()

			
	
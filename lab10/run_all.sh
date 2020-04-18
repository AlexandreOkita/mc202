for filein in testes_abertos/*.in ; do
	file=$(basename $filein .in)
	echo running $filein $file
	echo ./lab10 \< $filein \| diff - testes_abertos/$file.res
	./lab10 < $filein | diff - testes_abertos/$file.res
done

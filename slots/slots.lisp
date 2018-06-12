;;; Slots from Miki with several test functions

(defun make-repeated-array (table)
  (let* ((length (reduce #'(lambda (s x) (+ s (cdr x)))
			 table
			 :initial-value 0))
	 (result (make-array length))
	 (index 0))
    (dolist (pair table result)
      (dotimes (i (cdr pair))
	(setf (aref result index) (car pair))
	(incf index)))))

(defun hash-table-alist (alist)
  (let ((res (make-hash-table)))
    (dolist (elt alist res)
      (setf (gethash (car elt) res) (cdr elt)))))

(defun array-rand-elt (array)
  (aref array (random (array-dimension array 0))))

(defparameter *object-descr*
  '((cherry .		4) (orange .		3)
    (strawberry .	2) (pineapple .		2)
    (grape .		2) (watermelon .	2)
    (star .		2) (watermelon .	1)
    (pineapple .	2) (strawberry .	2)
    (orange .		3) (cherry .		4)))

(defparameter *slot-length* 3)

(defparameter *objects*
  (make-repeated-array *object-descr*))

(defparameter *coefs-descr*
  '((cherry .		#(0.0 0.5 1.0))
    (orange .		#(0.0 0.8 1.5))
    (strawberry .	#(0.0 1.0 2.0))
    (pineapple .	#(0.0 1.0 4.0))
    (grape .		#(0.0 1.2 6.0))
    (watermelon .	#(0.0 1.5 10.0))
    (star .		#(0.0 2.0 12.0))))

(defparameter *coefs* (hash-table-alist *coefs-descr*))

(defun choose-rand-obj ()
  (array-rand-elt *objects*))

(defun make-counts (sl)
  (let ((sorted (sort sl #'string-lessp))
	(res (make-hash-table)))
    (dotimes (i (array-dimension sorted 0) res)
      (incf (gethash (aref sorted i) res 0)))))

(defun make-sl ()
  (let ((r (make-array *slot-length*)))
    (dotimes (i *slot-length* r)
      (setf (aref r i) (choose-rand-obj)))))

(defun gamble (&optional (gamble 1.0))
  (let* ((res 0.0)
	 (cnts (make-counts (make-sl))))
    (maphash #'(lambda (k v)
		 (incf res (* gamble
			      (aref (gethash k *coefs*)
				    (1- v)))))
	     cnts)
    (if (zerop res)
	(- gamble)
	res)))

(defun expectation (n)
  (let ((s 0.0))
    (dotimes (i n (/ s n))
      (incf s (gamble)))))

(defun pmf (n)
  (let ((ht (make-hash-table :test 'equal)) res)
    (dotimes (i n)
      (incf (gethash (gamble) ht 0)))
    (maphash #'(lambda (k v)
		 (push (cons k (/ (float v) n))
		       res))
	     ht)
    (sort res #'(lambda (a b) (< (car a) (car b))))))

(defun strategy1 (n initial frac)
  (let* ((cur initial)
	 (g (round (* cur frac)))
	 (next (+ g cur)))
    (dotimes  (i n cur)
      (if (<= next cur)
	  (setf g (* cur frac)
		next (+ cur g))
	  (setf g (min cur (- next cur))))
      
      (incf cur (round (gamble g)))
      (if (zerop cur)
	  (return cur)))))

(defun strategy2 (n initial frac)
  (let ((cur initial))
    (dotimes (i n cur)
      (let ((g (round (* frac cur))))
	(incf cur (round (gamble (if (zerop g) cur g)))))
      (if (<= cur 1)
	  (return cur)))))

(defun strategy3 (n initial amount)
  (let ((cur initial))
    (dotimes (i n cur)
      (let ((g (min cur amount)))
	(incf cur (ceiling (gamble g))))
      (if (<= cur 1)
	  (return cur)))))

(defun expectation-ceiling (n)
  (do ((i 1 (1+ i))
       (s 0 (+ s (ceiling (gamble)))))
      ((>= i n) (/ (float s) n))))

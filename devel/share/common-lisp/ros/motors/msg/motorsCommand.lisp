; Auto-generated. Do not edit!


(cl:in-package motors-msg)


;//! \htmlinclude motorsCommand.msg.html

(cl:defclass <motorsCommand> (roslisp-msg-protocol:ros-message)
  ((deltaX
    :reader deltaX
    :initarg :deltaX
    :type cl:integer
    :initform 0)
   (deltaY
    :reader deltaY
    :initarg :deltaY
    :type cl:integer
    :initform 0)
   (faceArea
    :reader faceArea
    :initarg :faceArea
    :type cl:integer
    :initform 0)
   (setnence
    :reader setnence
    :initarg :setnence
    :type cl:string
    :initform ""))
)

(cl:defclass motorsCommand (<motorsCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motorsCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motorsCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motors-msg:<motorsCommand> is deprecated: use motors-msg:motorsCommand instead.")))

(cl:ensure-generic-function 'deltaX-val :lambda-list '(m))
(cl:defmethod deltaX-val ((m <motorsCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motors-msg:deltaX-val is deprecated.  Use motors-msg:deltaX instead.")
  (deltaX m))

(cl:ensure-generic-function 'deltaY-val :lambda-list '(m))
(cl:defmethod deltaY-val ((m <motorsCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motors-msg:deltaY-val is deprecated.  Use motors-msg:deltaY instead.")
  (deltaY m))

(cl:ensure-generic-function 'faceArea-val :lambda-list '(m))
(cl:defmethod faceArea-val ((m <motorsCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motors-msg:faceArea-val is deprecated.  Use motors-msg:faceArea instead.")
  (faceArea m))

(cl:ensure-generic-function 'setnence-val :lambda-list '(m))
(cl:defmethod setnence-val ((m <motorsCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motors-msg:setnence-val is deprecated.  Use motors-msg:setnence instead.")
  (setnence m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motorsCommand>) ostream)
  "Serializes a message object of type '<motorsCommand>"
  (cl:let* ((signed (cl:slot-value msg 'deltaX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'deltaY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'faceArea)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'setnence))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'setnence))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motorsCommand>) istream)
  "Deserializes a message object of type '<motorsCommand>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'deltaX) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'deltaY) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'faceArea) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'setnence) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'setnence) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motorsCommand>)))
  "Returns string type for a message object of type '<motorsCommand>"
  "motors/motorsCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motorsCommand)))
  "Returns string type for a message object of type 'motorsCommand"
  "motors/motorsCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motorsCommand>)))
  "Returns md5sum for a message object of type '<motorsCommand>"
  "c9eec707e4d0b5f449400290d53d427d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motorsCommand)))
  "Returns md5sum for a message object of type 'motorsCommand"
  "c9eec707e4d0b5f449400290d53d427d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motorsCommand>)))
  "Returns full string definition for message of type '<motorsCommand>"
  (cl:format cl:nil "int32 deltaX~%int32 deltaY~%int32 faceArea~%string setnence~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motorsCommand)))
  "Returns full string definition for message of type 'motorsCommand"
  (cl:format cl:nil "int32 deltaX~%int32 deltaY~%int32 faceArea~%string setnence~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motorsCommand>))
  (cl:+ 0
     4
     4
     4
     4 (cl:length (cl:slot-value msg 'setnence))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motorsCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'motorsCommand
    (cl:cons ':deltaX (deltaX msg))
    (cl:cons ':deltaY (deltaY msg))
    (cl:cons ':faceArea (faceArea msg))
    (cl:cons ':setnence (setnence msg))
))

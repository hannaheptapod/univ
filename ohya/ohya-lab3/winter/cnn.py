from keras.layers import Dense, Dropout, Flatten, Activation
from keras.layers import Conv2D, MaxPooling2D, Input, BatchNormalization
from keras.models import Sequential, load_model, Model
from keras.applications.vgg16 import VGG16
from keras.optimizers import SGD
from keras.preprocessing import image
import numpy as np
import matplotlib.pyplot as plt
import ssl
ssl._create_default_https_context = ssl._create_unverified_context
epochs = 10

# epoch毎のaccuracyとlossをグラフにプロットする
def show_graph(history):

    # Setting Parameters
    acc = history.history['acc']
    val_acc = history.history['val_acc']
    loss = history.history['loss']
    val_loss = history.history['val_loss']

    epochs = range(len(acc))

    # 1) Accracy Plt
    plt.plot(epochs, acc, 'bo', label='training acc')
    plt.plot(epochs, val_acc, 'b', label='validation acc')
    plt.title('Training and Validation acc')
    plt.legend()

    plt.figure()

    # 2) Loss Plt
    plt.plot(epochs, loss, 'bo', label='training loss')
    plt.plot(epochs, val_loss, 'b', label='validation loss')
    plt.title('Training and Validation loss')
    plt.legend()
    plt.show()

# データセットからデータを取得する
(X_train, y_train, X_test, y_test) = np.load('データセットのPATH')
X_train = np.array(X_train)
X_train = X_train.astype('float32')
X_train /= 255
y_train = np.array(y_train)
X_test = np.array(X_test)
X_test = X_test.astype('float32')
X_test /= 255
y_test = np.array(y_test)

datagen = image.ImageDataGenerator(
    rotation_range=20,
    width_shift_range=0.2,
    height_shift_range=0.2
)
datagen.fit(X_train)

input_tensor = Input(shape=(64, 64, 3))

# VGG16のデータを読み込む
vgg16 = VGG16(include_top=False, weights='imagenet', input_tensor=input_tensor)

top_model = Sequential()
top_model.add(Flatten(input_shape=vgg16.output_shape[1:]))
top_model.add(Dense(256, activation='relu'))
top_model.add(BatchNormalization())
top_model.add(Dropout(0.5))
top_model.add(Dense(2, activation='softmax'))

# vgg16とtop_modelを連結する
model = Model(inputs=vgg16.input, outputs=top_model(vgg16.output))

# 19層目までの重みをfor文を用いて固定する
for layer in model.layers[:19]:
    layer.trainable = False
model.summary()

model.compile(loss='categorical_crossentropy',
              optimizer=SGD(lr=1e-4, momentum=0.9),
              metrics=['accuracy'])

history = model.fit_generator(datagen.flow(X_train, y_train, batch_size=32),
                    steps_per_epoch=len(X_train)/32, epochs=epochs, validation_data=(X_test, y_test))

# 精度の評価
scores = model.evaluate(X_test, y_test, verbose=1)
print('Test loss:', scores[0])
print('Test accuracy:', scores[1])
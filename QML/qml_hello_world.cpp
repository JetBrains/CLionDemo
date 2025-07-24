#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  engine.load(QUrl::fromLocalFile("hello_world.qml"));
  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return QGuiApplication::exec();
}

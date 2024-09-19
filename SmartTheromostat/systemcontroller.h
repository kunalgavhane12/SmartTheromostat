#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include <QObject>

class SystemController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentSystemTemperature READ currentSystemTemperature WRITE setCurrentSystemTemperature NOTIFY currentSystemTemperatureChanged)
    Q_PROPERTY(int targetTemp READ targetTemp WRITE setTargetTemp NOTIFY targetTempChanged)
    Q_PROPERTY(QString systemStatusMessage READ systemStatusMessage WRITE setSystemStatusMessage NOTIFY systemStatusMessageChanged)
    Q_PROPERTY(HeatSelectState systemState READ systemState WRITE setSystemState NOTIFY systemStateChanged)
public:
    explicit SystemController(QObject *parent = nullptr);

    enum HeatSelectState {
        HEATING,
        COOLING,
        AUTO
    };
    Q_ENUM( HeatSelectState )

    int targetTemp() const;
    QString systemStatusMessage() const;
    HeatSelectState systemState() const;

    int currentSystemTemperature() const;
    void setCurrentSystemTemperature(int newCurrentSystemTemperature);

public slots:
    void setTargetTemp(int targetTemp);
    void setSystemStatusMessage(QString systemStatusMessage);
    void setSystemState(HeatSelectState systemState);

signals:
    void targetTempChanged(int targetTemp);

    void systemStatusMessageChanged(QString systemStatusMessage);

    void systemStateChanged(HeatSelectState systemState);

    void currentSystemTemperatureChanged(int currentTemp);

private:
    void checkSystemStatus();
    int m_currentSystemTemperature;
    int m_targetTemp;
    QString m_systemStatusMessage;
    HeatSelectState m_systemState;
};

#endif // SYSTEMCONTROLLER_H

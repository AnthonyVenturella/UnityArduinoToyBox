//TODO:
//  - Polish the code
//  - Prompt user for input of PortName
//  - Prompt User for input of BaudRate

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;


public class JoystickSerial : MonoBehaviour{

    [SerializeField] GameObject moveableBox;

    static SerialPort connection;

    //TODO: make these fillable by the user
    string portName = "COM3";
    int baudRate = 9600;

    void Start() {
        connection = new SerialPort();

        connection.PortName = portName;
        connection.BaudRate = baudRate;

        //TODO: replace above with func calls that prompt user
        //connection.PortName = SetPortName(connection.PortName);
        //connection.BaudRate = SetBaudRate(connection.BaudRate);

        connection.ReadTimeout = 5;
        //connection.WriteTimeout = 5; //for use in code that writes

        if (connection.IsOpen) { connection.Close(); Debug.Log("PORT WAS OPEN!"); } else { connection.Open(); }

    }

    void Update() {

        //only runs if there is something in serial
        if (connection.BytesToRead > 0) {

            //Serial input comes in in the form "0,0,0" corresponding to (Button, X-Axis, Y-Axis) We read this 
            //  in by taking input until first "," assigning to buttonVal, then again we read to second "," 
            //  assigning to X -Axis, and then we read the rest of the line assigning it to Y-Axis.
            //  If this doesnt work for you take a look at the other Read functions:
            //  https://docs.microsoft.com/en-us/dotnet/api/system.io.ports.serialport.read?view=netframework-4.8

            string buttonSerial = connection.ReadTo(",");
            string xAxisSerial = connection.ReadTo(",");
            string zAxisSerial = connection.ReadLine();
            int inputValue;
            int X, Z;

            if (buttonSerial == "1") {
                Debug.Log("Recieved Button Press");

                Color randomColor = new Color(Random.Range(0f, 1f), Random.Range(0f, 1f), Random.Range(0f, 1f));
                moveableBox.GetComponent<MeshRenderer>().material.color = randomColor;
            }

            if (int.TryParse(xAxisSerial, out inputValue)) {
                X = int.Parse(xAxisSerial);
            } else {
                X = -1;
            }

            if (int.TryParse(xAxisSerial, out inputValue)) {
                Z = int.Parse(zAxisSerial);
            } else {
                Z = -1;
            }

            //x and y axis are in values of 0-1023. A value of ~500 is the center with 0 and 1023 being the extremes
            float xPos = mapValue(X, 0, 1023, -25, 25);
            float zPos = mapValue(Z, 0, 1023, -25, 25);

            Debug.Log("X Unity World Value is: " + xPos);
            Debug.Log("Z Unity World Value is: " + zPos);

            moveableBox.transform.position = new Vector3(xPos, 0f, zPos);
        }
    }

    private void OnApplicationQuit() {
        //closes the port on app exit
        if (connection.IsOpen) { connection.Close(); }
    }

    private void OnDisable() {
        //closes the port on script disable. i.e. when a scene change happens if this isnt made persistent
        if (connection.IsOpen) { connection.Close(); }
    }

    public static float mapValue(float valueToMap, float fromMin, float fromMax, float toMin, float toMax) {
        return (valueToMap - fromMin) / (fromMax - fromMin) * (toMax - toMin) + toMin;
    }

    //TODO
    public static string SetPortName(string defaultPortName) {
        return "";
    }

    //TODO
    public static int setBaudRate(int defaultBaudRate) {
        return 0;
    }
}

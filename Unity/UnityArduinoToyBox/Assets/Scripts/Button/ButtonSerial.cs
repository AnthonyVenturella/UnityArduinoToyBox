//TODO:
//  - Polish the code
//  - Prompt user for input of PortName
//  - Prompt User for input of BaudRate

//snippits of code taken from example https://docs.microsoft.com/en-us/dotnet/api/system.io.ports.serialport?view=netframework-4.8

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;


public class ButtonSerial : MonoBehaviour{

    [SerializeField] GameObject coloredBox;

    static SerialPort connection;

    //TODO: make these fillable by the user
    string portName = "COM4";
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

        if (connection.IsOpen) { connection.Close(); Debug.Log("PORT WAS OPEN!"); } 
        else { connection.Open(); }

    }

    void Update() {

        //only runs if there is something in serial
        if (connection.BytesToRead > 0) {
            //Reads the serial one line at a time, so if printing to serial make sure you do seperate info on a new line
            //  If this doesnt work for you try any of the other functions: "Read" "ReadByte" ReadChar" "ReadExisting" "ReadTo"
            //  https://docs.microsoft.com/en-us/dotnet/api/system.io.ports.serialport.read?view=netframework-4.8

            string serialInput = connection.ReadLine();
            int inputValue;

            //checks if valid input then randomly sets the color
            if (int.TryParse(serialInput, out inputValue)) {
                Debug.Log("Recieved button Press value: " + inputValue);

                Color randomColor = new Color(Random.Range(0f, 1f), Random.Range(0f, 1f), Random.Range(0f, 1f));
                coloredBox.GetComponent<MeshRenderer>().material.color = randomColor;
            }
        }
    }

    private void OnApplicationQuit() {
        //closes the port on app exit
        if (connection.IsOpen) {connection.Close();}
    }

    private void OnDisable() {
        //closes the port on script disable. i.e. when a scene change happens if this isnt made persistent
        if (connection.IsOpen) { connection.Close(); }
    }

    //TODO
    public static string SetPortName(string defaultPortName) {
        /*string portName;

        //display ports to user somehow
        //print("Available Ports");
        foreach(string s in SerialPort.GetPortNames()) {
            //print("{0}, s);
        }

        //prompt user somehow to enter port and read value in
        //  user should type in form "com(some number)" i.e. "com3"
        portName = defaultPortName; //read from some input and assign here *TODO*

        if(portName == "" || !(defaultPortName.ToLower()).StartsWith("com")) {
            portName = defaultPortName;
        }

        return portName;*/

        //TODO: remove when done
        return defaultPortName;
    }

    //TODO
    public static int setBaudRate(int defaultBaudRate) {
        /*string baudRate = "";

        //prompt user to enter baud rate
        //print("Enter baud Rate: ");
        //baudRate = defaultPortName; //read in from some input and assign here *TODO*

        if (baudRate == "") {
            baudRate = defaultBaudRate.ToString();
        }

        return int.Parse(baudRate);*/

        //TODO: remove when done
        return 0;
    }
}

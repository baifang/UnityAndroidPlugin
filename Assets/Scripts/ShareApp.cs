using UnityEngine;
using System.Collections;

public class ShareApp : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	string subject = "WORD-O-MAZE";
	string body = "PLAY THIS AWESOME. GET IT ON THE PLAYSTORE";
	
	public void callShareApp(){
		AndroidJavaClass unity = new AndroidJavaClass ("com.unity3d.player.UnityPlayer");
		AndroidJavaObject currentActivity = unity.GetStatic<AndroidJavaObject> ("currentActivity");
		currentActivity.Call ("shareText", subject, body);
	}
}

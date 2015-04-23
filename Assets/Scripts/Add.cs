using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class Add : MonoBehaviour {
	//public TextMesh text3D;
	public UnityEngine.UI.Text text;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	int c = 0;
	void Update () {
//		if (text3D) {
//			text3D.text = JniAdd (0, c++).ToString ();
//		}
		if (text) {
			text.text = JniAdd (0, c++).ToString ();
		}
	}
	#if UNITY_IPHONE && !UNITY_EDITOR
	[DllImport ("__Internal")]
	#else
	[DllImport ("JniPlugin")]
	public static extern int JniAdd (int a, int b);
	#endif
}

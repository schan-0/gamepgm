using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GoalArea : MonoBehaviour
{
    public static bool goal;

    void Start() {
        goal = false;
        Debug.Log("GoalArea script started");
    }

    private void OnTriggerEnter(Collider col) {
        Debug.Log("Collision detected with: " + col.gameObject.name);
        if(col.gameObject.tag == "Player") {
            goal = true;
            Debug.Log("Player has reached the goal area!");
        }
    }
}

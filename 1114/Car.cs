using UnityEngine;

public class Car : MonoBehaviour {
    public float speed = .1f;

    void Update() {
        float x = Input.GetAxis("Horizontal");
        float z = Input.GetAxis("Vertical");

        Vector3 moveDirection = new Vector3(x, 0.0f, z);

        transform.position += moveDirection * speed;
    }
}